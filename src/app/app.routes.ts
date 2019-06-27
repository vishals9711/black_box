import { ModuleWithProviders } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { DevicesComponent } from './components/devices/devices.component';
import { LoginComponent } from './components/login/login.component';
import { SignupComponent } from './components/signup/signup.component';
import { StatusComponent } from './components/status/status.component';






export const routes: Routes = [
  { path: '', redirectTo: '/login', pathMatch: 'full' },
  { path: 'devices', component: DevicesComponent },
  { path: 'status', component: StatusComponent },
  { path: 'login', component: LoginComponent },
  { path: 'signup', component: SignupComponent }

];

export const routing: ModuleWithProviders = RouterModule.forRoot(routes);